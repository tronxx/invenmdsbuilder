object Frame_imginven: TFrame_imginven
  Left = 0
  Top = 0
  Width = 622
  Height = 416
  TabOrder = 0
  object Splitter1: TSplitter
    Left = 359
    Top = 0
    Width = 3
    Height = 416
    Cursor = crHSplit
    Align = alRight
  end
  object pnl_imagen: TPanel
    Left = 0
    Top = 0
    Width = 359
    Height = 416
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object grp_ajustaimg: TGroupBox
      Left = 0
      Top = 0
      Width = 359
      Height = 36
      Align = alTop
      TabOrder = 0
      object chk_ajustaimg: TCheckBox
        Left = 8
        Top = 10
        Width = 97
        Height = 17
        Action = ajusta_imagen
        TabOrder = 0
      end
      object btn_cambiaimg: TBitBtn
        Left = 104
        Top = 8
        Width = 121
        Height = 25
        Action = cambia_imagen
        Caption = 'Cambiar Imagen'
        TabOrder = 1
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00000000007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
          7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF0000000000BFBFBF00BFBFBF00BFBFBF000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000FF00FF0000000000FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF000000FF00FFFFFF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
          BF00BFBFBF00BFBFBF007F7F7F00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000000000000000000000000000000000000000000000
          00000000000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000FF000000FF000000FF000000FF000000FF000000FF
          000000FF000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000FF0000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF0000FF000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000FF00000000FF000000FF0000FF00000000FF000000
          FF0000FF000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000FF00000000FF000000FF0000FF00000000FF000000
          FF0000FF000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000FF000000FF000000FF000000FF000000FF000000FF
          000000FF000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F000000000000000000000000000000000000000000000000000000
          00000000000000000000BFBFBF00FFFFFF0000000000FF00FF0000000000FFFF
          FF007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
          7F007F7F7F007F7F7F007F7F7F00FFFFFF0000000000FF00FF0000000000FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000FF00FF00}
      end
      object BitBtn1: TBitBtn
        Left = 230
        Top = 9
        Width = 121
        Height = 25
        Action = agregar_imagen
        Caption = 'Agregar Imagen'
        TabOrder = 2
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF000000000000000000000000000000000000000000000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00000000000000FF000000FF000000FF000000FF000000FF000000FF000000
          FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
          00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
          FF00000000000000800000000000FF00FF00FF00FF00FF00FF00000000000000
          0000000080000000800000008000000080000000800000008000000080000000
          800000000000000080000000800000000000FF00FF00FF00FF00000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000080000000800000000000FF00FF00FF00FF000000
          00007F7F7F0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF0000000000FFFFFF0000000000000080000000800000000000FF00FF00FF00
          FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF0000000000FFFFFF0000000000000000000000800000000000FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF007F7F7F0000000000000000000000
          000000000000FFFFFF0000000000FFFFFF000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00000000000000000000000000FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000FFFFFF000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF007F7F7F000000
          0000000000000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFF
          FF007F7F7F0000000000000000000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      end
    end
    object scroll_boximg: TScrollBox
      Left = 0
      Top = 36
      Width = 359
      Height = 380
      Align = alClient
      TabOrder = 1
      object img_principal: TImage
        Left = 0
        Top = 0
        Width = 261
        Height = 140
        AutoSize = True
      end
    end
  end
  object grp_listasimagenes: TGroupBox
    Left = 362
    Top = 0
    Width = 260
    Height = 416
    Align = alRight
    Caption = 'Im�genes'
    TabOrder = 1
    Visible = False
    object dbgrd_imagenes: TdxDBGrid
      Left = 2
      Top = 104
      Width = 256
      Height = 177
      Bands = <
        item
        end>
      DefaultLayout = True
      HeaderPanelRowCount = 1
      KeyField = 'NIMG'
      SummaryGroups = <>
      SummarySeparator = ', '
      Align = alTop
      TabOrder = 0
      DataSource = dts_folsel
      Filter.Criteria = {00000000}
      OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
      object dbgrd_imagenesIDMAGEN: TdxDBGridMaskColumn
        Caption = 'Num'
        Width = 28
        BandIndex = 0
        RowIndex = 0
        FieldName = 'NIMG'
      end
      object dbgrd_imagenesNOMARCH: TdxDBGridMaskColumn
        Caption = 'Archivo'
        Width = 93
        BandIndex = 0
        RowIndex = 0
        FieldName = 'NOMARCH'
      end
    end
    object Panel1: TPanel
      Left = 2
      Top = 15
      Width = 256
      Height = 89
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 122
        Height = 13
        Caption = 'Directorio Base Lan Local'
      end
      object Label2: TLabel
        Left = 8
        Top = 48
        Width = 125
        Height = 13
        Caption = 'Directorio Base Generador'
      end
      object edt_dirbaselan: TEdit
        Left = 8
        Top = 24
        Width = 241
        Height = 21
        TabOrder = 0
      end
      object edt_dirpython: TEdit
        Left = 7
        Top = 64
        Width = 241
        Height = 21
        TabOrder = 1
      end
    end
    object grp_fotosact: TGroupBox
      Left = 2
      Top = 281
      Width = 256
      Height = 133
      Align = alClient
      Caption = 'Fotos Actualizadas'
      TabOrder = 2
      object mmo_fotos_actualizadas: TMemo
        Left = 2
        Top = 15
        Width = 252
        Height = 116
        Align = alClient
        Lines.Strings = (
          'mmo_fotos_actualizadas')
        TabOrder = 0
      end
    end
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 210
    Top = 210
    object ajusta_imagen: TAction
      Caption = 'Ajustar Imagen'
      OnExecute = ajusta_imagenExecute
    end
    object cambia_imagen: TAction
      Caption = 'Cambiar Imagen'
      ImageIndex = 37
      Visible = False
      OnExecute = cambia_imagenExecute
    end
    object agregar_imagen: TAction
      Caption = 'Agregar Imagen'
      ImageIndex = 23
      Visible = False
      OnExecute = agregar_imagenExecute
    end
  end
  object qry_folsel: TQuery
    CachedUpdates = True
    AfterScroll = qry_folselAfterScroll
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select idconcep as nimg, concep as nomarch'
      'from inv_conceps where idconcep = -100'
      ' ')
    UpdateObject = uqry_folsel
    Left = 343
    Top = 72
  end
  object uqry_folsel: TUpdateSQL
    Left = 344
    Top = 104
  end
  object dts_folsel: TDataSource
    DataSet = qry_folsel
    Left = 344
    Top = 137
  end
end
