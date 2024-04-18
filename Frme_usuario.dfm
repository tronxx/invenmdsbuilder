object Frame_usuario: TFrame_usuario
  Left = 0
  Top = 0
  Width = 433
  Height = 337
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 433
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 15
      Width = 33
      Height = 13
      Caption = '&Código'
      FocusControl = edt_codvnd
    end
    object Label2: TLabel
      Left = 12
      Top = 37
      Width = 37
      Height = 13
      Caption = 'Nombre'
    end
    object Label3: TLabel
      Left = 23
      Top = 61
      Width = 26
      Height = 13
      Caption = 'Login'
    end
    object Label4: TLabel
      Left = 181
      Top = 62
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object Label5: TLabel
      Left = 124
      Top = 14
      Width = 28
      Height = 13
      Caption = 'Póliza'
    end
    object Label7: TLabel
      Left = 261
      Top = 14
      Width = 38
      Height = 13
      Caption = 'Iniciales'
    end
    object lbl_fecbaja: TLabel
      Left = 123
      Top = 108
      Width = 54
      Height = 13
      Caption = 'Fecha Baja'
    end
    object edt_nombre: TdxEdit
      Left = 51
      Top = 34
      Width = 304
      TabOrder = 3
      CharCase = ecUpperCase
    end
    object edt_login: TdxEdit
      Left = 51
      Top = 58
      Width = 120
      TabOrder = 4
      CharCase = ecUpperCase
      MaxLength = 15
      StoredValues = 2
    end
    object edt_passw: TdxEdit
      Left = 234
      Top = 58
      Width = 120
      TabOrder = 5
      CharCase = ecUpperCase
      MaxLength = 15
      PasswordChar = '*'
      StoredValues = 2
    end
    object chk_maestro: TCheckBox
      Left = 52
      Top = 83
      Width = 74
      Height = 17
      Caption = '&Maestro'
      TabOrder = 6
    end
    object edt_numpol: TEdit
      Left = 156
      Top = 10
      Width = 47
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 3
      TabOrder = 1
    end
    object edt_codvnd: TdxCurrencyEdit
      Left = 52
      Top = 10
      Width = 61
      TabOrder = 0
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = '0;-0'
      StoredValues = 1
    end
    object chk_verpwd: TCheckBox
      Left = 181
      Top = 83
      Width = 113
      Height = 17
      Caption = 'Passwords &Visibles'
      TabOrder = 7
      OnClick = chk_verpwdClick
    end
    object edt_iniciales: TEdit
      Left = 309
      Top = 10
      Width = 47
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 2
    end
    object chk_baja: TCheckBox
      Left = 52
      Top = 107
      Width = 63
      Height = 17
      Caption = 'Baja'
      TabOrder = 8
      OnClick = chk_bajaClick
    end
    object date_fecbaja: TDateTimePicker
      Left = 181
      Top = 104
      Width = 176
      Height = 21
      CalAlignment = dtaLeft
      Date = 42101.5664897917
      Time = 42101.5664897917
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 9
    end
  end
  object grp_permisiones: TGroupBox
    Left = 0
    Top = 137
    Width = 433
    Height = 72
    Align = alTop
    Caption = 'Permisiones Disponibles'
    TabOrder = 1
    object Label10: TLabel
      Left = 8
      Top = 19
      Width = 23
      Height = 13
      Caption = 'Perfil'
      FocusControl = lkcmb_perfil
    end
    object lkcmb_perfil: TDBLookupComboBox
      Left = 48
      Top = 16
      Width = 289
      Height = 21
      KeyField = 'IDPERFIL'
      ListField = 'CLAVE'
      ListSource = dts_perfiles
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 48
      Top = 39
      Width = 289
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_perfiles
      TabOrder = 1
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 209
    Width = 433
    Height = 128
    Align = alClient
    Caption = 'Permisiones Otorgadas'
    TabOrder = 2
    object dbgrd_permis: TdxDBGrid
      Left = 2
      Top = 15
      Width = 429
      Height = 111
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
      DataSource = dts_permisiones
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
      'select a.*, b.descripcion'
      'from car_perfildet a'
      'join car_permisiones b on a.idpermis = b.idpermis'
      'join fac_permiproyectos c on b.idpermis = c.idpermis'
      'where'
      'a.idperfil = :IDPERFIL'
      'order by descripcion'
      ''
      ' ')
    Left = 184
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDPERFIL'
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
      'select permiso, descripcion '
      'from car_permisos'
      'order by permiso')
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
      'select * from car_perfilusuario'
      'where idusuario = :IDUSUARIO '
      ''
      '')
    UpdateObject = uqry_permgrant
    Left = 328
    Top = 264
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDUSUARIO'
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
      'update car_perfilusuario'
      'set'
      '  IDPERFIL = :IDPERFIL'
      'where'
      '  IDPERFILUSUARIO = :OLD_IDPERFILUSUARIO')
    InsertSQL.Strings = (
      'insert into car_perfilusuario'
      '  (IDPERFILUSUARIO, IDPERFIL, IDUSUARIO)'
      'values'
      '  (:IDPERFILUSUARIO, :IDPERFIL, :IDUSUARIO)'
      ' ')
    DeleteSQL.Strings = (
      'delete from car_perfilusuario'
      'where'
      '  IDPERFILUSUARIO = :OLD_IDPERFILUSUARIO')
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
    AfterScroll = qry_perfilesAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from car_perfil order by clave'
      ' ')
    UpdateObject = uqry_permisos
    Left = 146
    Top = 232
  end
  object dts_perfiles: TDataSource
    DataSet = qry_perfiles
    Left = 146
    Top = 264
  end
end
