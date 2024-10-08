object Frame_perfil: TFrame_perfil
  Left = 0
  Top = 0
  Width = 433
  Height = 337
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 433
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 15
      Width = 27
      Height = 13
      Caption = 'Clave'
    end
    object Label2: TLabel
      Left = 9
      Top = 37
      Width = 37
      Height = 13
      Caption = 'Nombre'
    end
    object edt_clave: TEdit
      Left = 51
      Top = 11
      Width = 300
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 20
      TabOrder = 0
    end
    object edt_descri: TEdit
      Left = 51
      Top = 35
      Width = 300
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 50
      TabOrder = 1
    end
  end
  object grp_permisiones: TGroupBox
    Left = 0
    Top = 65
    Width = 433
    Height = 72
    Align = alTop
    Caption = 'Permisiones Disponibles'
    TabOrder = 1
    object Label10: TLabel
      Left = 8
      Top = 19
      Width = 45
      Height = 13
      Caption = 'Permisión'
      FocusControl = lkcmb_perfil
    end
    object Label3: TLabel
      Left = 8
      Top = 43
      Width = 40
      Height = 13
      Caption = 'Permiso '
      FocusControl = lkcmb_permisos
    end
    object lkcmb_perfil: TDBLookupComboBox
      Left = 56
      Top = 16
      Width = 289
      Height = 21
      KeyField = 'idpermis'
      ListField = 'DESCRIPCION'
      ListSource = dts_permisiones
      TabOrder = 0
    end
    object BitBtn1: TBitBtn
      Left = 352
      Top = 16
      Width = 75
      Height = 25
      Action = agregar_permi
      Caption = 'Agregar'
      TabOrder = 2
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
        FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
        FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
        0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
        0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
        0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    end
    object lkcmb_permisos: TDBLookupComboBox
      Left = 56
      Top = 40
      Width = 289
      Height = 21
      KeyField = 'PERMISO'
      ListField = 'DESCRIPCION'
      ListSource = dts_permisos
      TabOrder = 1
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 137
    Width = 433
    Height = 200
    Align = alClient
    Caption = 'Permisiones Otorgadas'
    TabOrder = 2
    object dbgrd_permis: TdxDBGrid
      Left = 2
      Top = 15
      Width = 429
      Height = 183
      Bands = <
        item
        end>
      DefaultLayout = True
      HeaderPanelRowCount = 1
      KeyField = 'IDPERFILDET'
      SummaryGroups = <>
      SummarySeparator = ', '
      Align = alClient
      PopupMenu = PopupMenu1
      TabOrder = 0
      OnKeyDown = dbgrd_permisKeyDown
      DataSource = dts_permgrant
      Filter.Criteria = {00000000}
      OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
      OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
      object dbgrd_permisDESCRIPCION: TdxDBGridMaskColumn
        Caption = 'Permisión'
        Width = 270
        BandIndex = 0
        RowIndex = 0
        FieldName = 'DESCRIPCION'
      end
      object dbgrd_permisPERMIS: TdxDBGridMaskColumn
        Caption = 'Permiso'
        BandIndex = 0
        RowIndex = 0
        FieldName = 'PERMIS'
      end
    end
  end
  object qry_permisiones: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select b.*'
      'from car_permisiones b'
      'join fac_permiproyectos c on b.idpermis = c.idpermis'
      'where'
      'c.idproyecto = :IDPROYECTO'
      'order by descripcion'
      '')
    Left = 184
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDPROYECTO'
        ParamType = ptUnknown
      end>
  end
  object dts_permisiones: TDataSource
    DataSet = qry_permisiones
    Left = 182
    Top = 264
  end
  object qry_permisos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select permiso, descripcion'
      'from car_permisos'
      'order by permiso'
      ' ')
    Left = 218
    Top = 232
  end
  object dts_permisos: TDataSource
    DataSet = qry_permisos
    Left = 218
    Top = 264
  end
  object uqry_permisos: TUpdateSQL
    Left = 220
    Top = 299
  end
  object qry_permgrant: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.*, b.descripcion'
      
        'from car_perfildet a join car_permisiones b on a.idpermis = b.id' +
        'permis'
      'where a.idperfil = :IDPERFIL'
      ''
      ' ')
    UpdateObject = uqry_permgrant
    Left = 328
    Top = 264
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDPERFIL'
        ParamType = ptUnknown
      end>
  end
  object dts_permgrant: TDataSource
    AutoEdit = False
    DataSet = qry_permgrant
    Left = 326
    Top = 296
  end
  object uqry_permgrant: TUpdateSQL
    ModifySQL.Strings = (
      'update car_perfildet'
      'set'
      '  IDPERFIL = :IDPERFIL,'
      '  IDPERMIS = :IDPERMIS,'
      '  PERMIS = :PERMIS'
      'where'
      '  IDPERFILDET = :OLD_IDPERFILDET')
    InsertSQL.Strings = (
      'insert into car_perfildet'
      '  (IDPERFILDET, IDPERFIL, IDPERMIS, PERMIS, CIA)'
      'values'
      '  (:IDPERFILDET, :IDPERFIL, :IDPERMIS, :PERMIS, :CIA)')
    DeleteSQL.Strings = (
      'delete from car_perfildet'
      'where'
      '  IDPERFILDET = :OLD_IDPERFILDET')
    Left = 359
    Top = 264
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 296
    Top = 270
    object exportar: TAction
      Caption = 'Exportar a...'
      ImageIndex = 19
      OnExecute = exportarExecute
    end
    object agregar_permi: TAction
      Caption = 'Agregar'
      ImageIndex = 13
      OnExecute = agregar_permiExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 112
    Top = 270
    object Exportara1: TMenuItem
      Action = exportar
    end
  end
  object qry_perfiles: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from car_perfil where idperfil = :IDPERFIL'
      ' ')
    UpdateObject = uqry_permisos
    Left = 146
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDPERFIL'
        ParamType = ptUnknown
      end>
  end
  object dts_perfiles: TDataSource
    DataSet = qry_perfiles
    Left = 146
    Top = 264
  end
end
